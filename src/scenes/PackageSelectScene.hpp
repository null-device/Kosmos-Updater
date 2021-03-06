// Kosmos Updater
// Copyright (C) 2018 Steven Mattera
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#pragma once

#include "../Scene.hpp"
#include "../views/HeaderView.hpp"
#include "../views/UpdateView.hpp"
#include "../views/StatusView.hpp"
#include "../views/ListHeaderView.hpp"
#include "../views/ListRowView.hpp"
#include "../views/FooterView.hpp"
#include "../views/MultiSelectView.hpp"
#include "../views/AlertView.hpp"
#include "../models/NetRequest.hpp"
#include "../ModalView.hpp"

class PackageSelectScene : public Scene {
    public:
        PackageSelectScene();
        ~PackageSelectScene();

        void handleButton(u32 buttons);
        void render(SDL_Rect rect, double dTime);

    private:
        string _latestVersion;
        bool _channelOpen;
        string _channelSelected;
        bool _bundleOpen;
        string _bundleSelected;
        int _focusSelection;
        bool _disabledGameCart;
        
        NetRequest * _versionRequest;

        HeaderView * _headerView;
        UpdateView * _updateView;
        StatusView * _statusView;
        ListRowView * _installRowView;
        ListHeaderView * _settingHeaderView;
        ListRowView * _channelRowView;
        ListRowView * _bundleRowView;
        ListRowView * _disableGCRowView;
        FooterView * _footerView;

        MultiSelectView * _channelMultiSelectView;
        MultiSelectView * _bundleMultiSelectView;
        AlertView * _disabledGameCartAlertView;
        
        void _updateVersionRequest();
        void _showUpdateView();
        void _showPackageSelectViews();
        void _showStatusView(string text, string subtext);
        
        void _manageFocus();

        void _onMultiSelectDismiss(ModalView * view, bool success);
        void _onAlertViewDismiss(ModalView * view, bool success);
        void _handleButtonsForChannelMutliSelect(u32 buttons);
        void _handleButtonsForBundleMutliSelect(u32 buttons);
        void _resetVersion(bool channelChange);
};
